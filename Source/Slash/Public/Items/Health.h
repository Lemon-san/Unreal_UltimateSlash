// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "Health.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_API AHealth : public AItem
{
	GENERATED_BODY()

public:

protected:
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

private:

	UPROPERTY(EditAnywhere, Category = "Health Properties")
	float HealthOrb;

public:

	FORCEINLINE const float GetHealthOrb() { return HealthOrb; };
};
