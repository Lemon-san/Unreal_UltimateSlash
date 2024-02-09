// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/SlashHUD.h"
#include "HUD/SlashOverlay.h"

void ASlashHUD::BeginPlay()
{
	Super::BeginPlay();

	if (!GetWorld()) return;

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	if (PlayerController && SlashOverlayClass)
	{
		SlashOverlay = CreateWidget<USlashOverlay>(PlayerController,SlashOverlayClass);
		SlashOverlay->AddToViewport();
	}
	
}
