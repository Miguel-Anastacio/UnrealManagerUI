// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreGameHUD.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/MainMenuWidget.h"
void ACoreGameHUD::BeginPlay()
{
	Super::BeginPlay();
	// Adding widgets to menu layer
	if (MainMenuClass)
	{/*
		UMainMenuWidget* MainMenu = CreateWidget<UMainMenuWidget>(GetOwningPlayerController(), MainMenuClass);

		MainMenu->AddToViewport();

		PushToLayer(FString("Menu"), MainMenu);*/
	}
	//if(OptionsMenuClass)
	//	PushToLayer(FString("Menu"), CreateWidget<UUserWidget>(GetOwningPlayerController(), OptionsMenuClass));
	if (HUDClass)
		PushToLayer(FString("Game"), CreateWidget<UUserWidget>(GetOwningPlayerController(), HUDClass));
	if (ConfirmModalClass)
		PushToLayer(FString("Modal"), CreateWidget<UUserWidget>(GetOwningPlayerController(), ConfirmModalClass));
}

void ACoreGameHUD::ToggleInventory_Implementation()
{

}

void ACoreGameHUD::SetHUDWidget(UUserWidget* widget)
{
	HUDWidget = widget;
}

void ACoreGameHUD::SetInventoryWidget(UUserWidget* widget)
{
	InventoryWidget = widget;
}

void ACoreGameHUD::TogglePause_Implementation()
{

}
