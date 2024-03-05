// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreGameHUD.h"
#include "Blueprint/UserWidget.h"
void ACoreGameHUD::BeginPlay()
{
	Super::BeginPlay();
	// Adding widgets to menu layer
	if(MainMenuClass)
		PushToLayer(FString("Menu"), CreateWidget<UUserWidget>(GetOwningPlayerController(), MainMenuClass));
	//if(OptionsMenuClass)
	//	PushToLayer(FString("Menu"), CreateWidget<UUserWidget>(GetOwningPlayerController(), OptionsMenuClass));
	if (HUDClass)
		PushToLayer(FString("Game"), CreateWidget<UUserWidget>(GetOwningPlayerController(), HUDClass));
	if (ConfirmModalClass)
		PushToLayer(FString("Modal"), CreateWidget<UUserWidget>(GetOwningPlayerController(), ConfirmModalClass));
}
