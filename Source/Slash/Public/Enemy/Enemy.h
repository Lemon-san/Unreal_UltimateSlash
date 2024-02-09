// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "Characters/CharacterTypes.h"
#include "Enemy.generated.h"


class UHealthBarComponent;
class AAIController;
class UPawnSensingComponent;

UCLASS()
class SLASH_API AEnemy : public ABaseCharacter
{
	GENERATED_BODY()

public:

	AEnemy();

	/*<Actor>*/
	virtual void Tick(float DeltaTime) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	virtual void Destroyed() override;
	/*/<Actor>*/
	

	/*<IHitInterface>*/
	virtual void GetHit_Implementation(const FVector& ImpactPoint, const FVector& OtherActorLocation) override;
	/*/<IHitInterface>*/


protected:

	virtual void BeginPlay() override;
	
	virtual void Attack() override;
	virtual void DieMontage_Implementation() override;
	void SpawnSoul();
	virtual bool CanAttack() override;
	virtual void HandleDamage(float DamageAmount) override;
	virtual void AttackEnd() override;

	

	UPROPERTY(BlueprintReadOnly)
	EEnemyState EnemyState = EEnemyState::EES_Patrolling;

	bool InTargetRange(AActor* Target, double Radius);

	UFUNCTION()
	virtual void PawnSeen(APawn* Pawn); //callback to UPawn seen in PawnSensingComponent

	UPROPERTY(EditAnywhere, Category = "Combat")
	float DeathLifeSpan = 8.f;


	


private:

	/*
	AI Behavior
	*/
	void InitializeEnemy();
	void CheckPatrolTarget();
	void CheckCombatTarget();
	void PatrolTimerFinished();
	AActor* ChoosePatrolTarget();
	void HideHealthBar();
	void ShowHealthBar();
	void LoseInterest();
	void StartPatrolling();
	void ChaseTarget();
	bool IsOutsideCombatRadius();
	bool isOutsideAttackRadius();
	bool isInsideAttackRadius();
	bool isChasing();
	bool isAttacking();
	bool isDead();
	bool isEngaged();
	void StartAttackTimer();
	void ClearAttackTimer();
	void ClearPatrolTimer();
	void MoveToTarget(AActor* Target);
	void SpawnDefaultWeapon();
	

	UPROPERTY(VisibleAnywhere, Category = "Player Visibility")
	UPawnSensingComponent* PawnSensing;

	UPROPERTY(VisibleAnywhere, Category = "HUD")
	UHealthBarComponent* HealthBarWidget;

	/*
	Combat Variables
	*/
	

	UPROPERTY(EditAnywhere, Category = "Combat")
	double PatrolRadius = 200.f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	double CombatRadius = 1000.f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	double AttackRadius = 150.f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	double AcceptanceRadius = 50.f;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AWeapon> WeaponClass;

	/**
	Navigation
	*/

	UPROPERTY()
	AAIController* EnemyController;

	UPROPERTY(EditAnywhere, Category = "AI Navigation")
	float PatrolWaitMin = 0.f;

	UPROPERTY(EditAnywhere, Category = "AI Navigation")
	float PatrolWaitMax = 5.f;

	//Current patrol target
	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	AActor* PatrolTarget;

	//Change to new patrol target
	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	TArray<AActor*> PatrolTargets;

	FTimerHandle PatrolTimer;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float PatrollingSpeed = 125.f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float ChasingSpeed = 300.f;


	FTimerHandle AttackTimer;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float AttackMin = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float AttackMax = 1.f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<class ASoul> SoulClass;

};
