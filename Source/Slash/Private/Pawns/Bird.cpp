// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Bird.h"
#include <Components/CapsuleComponent.h>
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>

// Sets default values
ABird::ABird()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BirdCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("BirdCapsule"));
	SetRootComponent(BirdCapsule);

	BirdMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BirdMesh"));
	BirdMesh->SetupAttachment(BirdCapsule);

	BirdSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("BirdSpringArm"));
	BirdSpringArm->SetupAttachment(BirdCapsule);
	BirdSpringArm->TargetArmLength = 300.f;

	BirdCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("BirdCamera"));
	BirdCamera->SetupAttachment(BirdSpringArm);


	//AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void ABird::BeginPlay()
{
	Super::BeginPlay();

	//Add Input
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(BirdMappingContext, 0);
		}
	}
	
}



// Called every frame
void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhanceInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhanceInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABird::Move);
		EnhanceInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABird::Look);
	}

}


void ABird::Move(const FInputActionValue& Value)
{
	const float DirectionVector = Value.Get<float>();

	if (Controller && DirectionVector != 0.f)
	{
		FVector Forward = GetActorForwardVector();

		AddMovementInput(Forward, DirectionVector);
	}
}

void ABird::Look(const FInputActionValue& Value)
{
	FVector2D LookVector = Value.Get<FVector2D>();

	if (Controller)
	{
		AddControllerYawInput(LookVector.X); 
		AddControllerPitchInput(LookVector.Y); 
	}

}
