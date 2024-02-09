// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SlashOverlay.generated.h"


class UProgressBar;
class UTextBlock;
/**
 * 
 */
UCLASS()
class SLASH_API USlashOverlay : public UUserWidget
{
	GENERATED_BODY()
	
public:

private:

	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBarProgressBar;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* StaminaProgressBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* GoldCountText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* SoulCountText;

public:
	FORCEINLINE void SetHealthBarPercent(float Percent);
	FORCEINLINE void SetStaminaBarPercent(float Percent);
	FORCEINLINE void SetGoldCount(int32 Count);
	FORCEINLINE void SetSoulCount(int32 Count);
};
