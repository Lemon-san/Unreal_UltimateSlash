// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/SlashOverlay.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void USlashOverlay::SetHealthBarPercent(float Percent)
{
	if (HealthBarProgressBar)
	{
		HealthBarProgressBar->SetPercent(Percent);
	}
}

void USlashOverlay::SetStaminaBarPercent(float Percent)
{
	if (StaminaProgressBar)
	{
		StaminaProgressBar->SetPercent(Percent);
	}
}

void USlashOverlay::SetSoulCount(int32 Count)
{
	if (SoulCountText)
	{
		FText Text = FText::FromString(FString::Printf(TEXT("%d"), Count));
		SoulCountText->SetText(Text);
	}
}

void USlashOverlay::SetGoldCount(int32 Count)
{
	if (GoldCountText)
	{
		FText Text = FText::FromString(FString::Printf(TEXT("%d"), Count));
		GoldCountText->SetText(Text);
	}
}
