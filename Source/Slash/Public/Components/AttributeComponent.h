// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLASH_API UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UAttributeComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void RegenStamina(float DeltaTime);
protected:
	
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float CurrentHealth = 100.f;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float MaxHealth = 100.f;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float CurrentStamina = 100.f;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float MaxStamina = 100.f;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	int32 Gold;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	int32 Souls;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float DodgeCost = 15.f;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float StaminaRegenRate = 2.f;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float HealthGain = 25.f;

public:
	void SetReceiveDamage(float Damage);
	void UseStamina(float StaminaCost);
	bool isAlive();
	void AddSouls(int32 NumberOfSouls);
	void AddGold(int32 AmountOfGold);
	void AddHealth(float AmountOfHealth);

	FORCEINLINE float GetHealthPercent() { return CurrentHealth / MaxHealth; } ;
	FORCEINLINE float GetStaminaPercent() { return CurrentStamina / MaxStamina; };
	FORCEINLINE const int32 GetGold() { return Gold; };
	FORCEINLINE const int32 GetSouls() { return Souls; };
	FORCEINLINE float GetDodgeCost() { return DodgeCost; };
	FORCEINLINE const float GetStamina() { return CurrentStamina; };

	
};
