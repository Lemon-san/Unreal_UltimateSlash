// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Soul.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

void ASoul::BeginPlay()
{
	Super::BeginPlay();

	SoulLineTrace();

}

void ASoul::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SoulDrift(DeltaTime);
}

void ASoul::SoulDrift(float DeltaTime)
{
	const double ActorLocationAtZ = GetActorLocation().Z;

	if (ActorLocationAtZ > DesiredZ)
	{
		const FVector DeltaLocation = FVector(0.f, 0.f, DeltaTime * DriftRate);
		AddActorWorldOffset(DeltaLocation);
	}
}

void ASoul::SoulLineTrace()
{
	const FVector StartLocation = GetActorLocation();
	const FVector EndLocation = GetActorLocation() - FVector(0.f, 0.f, 2000.f);
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	TArray<AActor*> ActorsToIgnore;
	FHitResult HitResult;

	ActorsToIgnore.Add(GetOwner());
	ObjectTypes.Add(EObjectTypeQuery::ObjectTypeQuery1);


	UKismetSystemLibrary::LineTraceSingleForObjects(
		this,
		StartLocation,
		EndLocation,
		ObjectTypes,
		false,
		ActorsToIgnore,
		EDrawDebugTrace::None,
		HitResult,
		true);

	DesiredZ = HitResult.ImpactPoint.Z + 50.f;
}

void ASoul::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IPickupInterface* PickupInterface = Cast<IPickupInterface>(OtherActor);

	if (PickupInterface && PickupEffect)
	{
		PickupInterface->AddSouls(this);
		SpawnPickupSystem();
		PickupPlaySound();
		Destroy();
	}
	
}
