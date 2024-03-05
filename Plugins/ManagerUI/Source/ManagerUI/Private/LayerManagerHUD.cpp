// Fill out your copyright notice in the Description page of Project Settings.


#include "LayerManagerHUD.h"
#include "ManagerUI.h"

void ALayerManagerHUD::RegisterDefaultLayer(const FString& name)
{
	LayersUI.Add(name, NewObject<ULayerUI>());
}

void ALayerManagerHUD::RegisterLayer(const FString& name, ULayerUI* layer)
{
	if (layer)
	{
		LayersUI.Add(name, layer);
	}
	else
	{
		UE_LOG(LogManagerUI, Error, TEXT("ERROR - Tried to register invalid layer"));
	}
}

void ALayerManagerHUD::RemoveLayer(const FString& name)
{
	ULayerUI* layer;
	if (LayersUI.RemoveAndCopyValue(name, layer))
	{
		layer->ClearStack();
	}

	//LayersUI.Remove(name);
}

void ALayerManagerHUD::PushToLayer(const FString& name, UUserWidget* widget)
{
	ULayerUI* layer = LayersUI.FindOrAdd(name, NewObject<ULayerUI>());
	layer->PushToStack(widget);
}

UUserWidget* ALayerManagerHUD::PopFromLayer(const FString& name)
{
	ULayerUI** layer = LayersUI.Find(name);
	if (layer)
	{
		return (*layer)->PopFromStack();
	}
	return nullptr;
}

ULayerUI* ALayerManagerHUD::GetLayer(const FString& name)
{
	return (*LayersUI.Find(name));
}
