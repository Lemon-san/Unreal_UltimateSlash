// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Health.h"

void AHealth::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IPickupInterface* PickupInterface = Cast<IPickupInterface>(OtherActor);

	if (PickupInterface && PickupEffect)
	{
		PickupInterface->AddHealth(this);
		SpawnPickupSystem();
		PickupPlaySound();
		Destroy();
	}

}