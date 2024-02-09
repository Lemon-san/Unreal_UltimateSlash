// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/PickupInterface.h"
#include "Item.generated.h"

class USphereComponent;
class UNiagaraComponent;
class UNiagaraSystem;
class USoundBase;

enum class EItemState :uint8
{
	EIS_Hovering,
	EIS_Equipped
};

UCLASS()
class SLASH_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* ItemSphereCollision;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(VisibleAnywhere)
	UNiagaraComponent* ItemEffect;


	UPROPERTY(EditAnywhere)
	UNiagaraSystem* PickupEffect;

	UPROPERTY(EditAnywhere)
	USoundBase* PickupSound;

	UFUNCTION()
	float TransformSin() const;

	UFUNCTION()
	float TransformCos() const;

	template<typename T>
	T Avg(T First, T Second);

	EItemState ItemState = EItemState::EIS_Hovering;

	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void SpawnPickupSystem();
	virtual void PickupPlaySound();

	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
private:
	UPROPERTY(VisibleAnywhere, Category = "Time Parameters")
	float RunningTime;

	UPROPERTY(EditAnywhere, Category = "Time Parameters")
	float Amplitude = 1.5f;

	UPROPERTY(EditAnywhere, Category = "Time Parameters")
	float TimeConstant = 5.0f;



	
};


template<typename T>
inline T AItem::Avg(T First, T Second)
{
	return (First + Second)/2;
}
