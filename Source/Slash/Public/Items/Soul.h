// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "Interfaces/PickupInterface.h"
#include "Soul.generated.h"


class UNiagaraSystem;
/**
 * 
 */
UCLASS()
class SLASH_API ASoul : public AItem
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	


protected:
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

private:
	void SoulDrift(float DeltaTime);
	void SoulLineTrace();

	UPROPERTY(EditAnywhere, Category = "Soul Properties")
	int32 Souls;

	UPROPERTY(VisibleAnywhere)
	double DesiredZ;

	UPROPERTY(EditAnywhere)
	float DriftRate = -15.f;

public:
	FORCEINLINE const int32 GetSouls() { return Souls; };
	FORCEINLINE void SetSouls(int32 NumberOfSouls) { Souls = NumberOfSouls; };
};
