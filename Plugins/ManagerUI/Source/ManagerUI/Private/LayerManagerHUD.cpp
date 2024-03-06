// Fill out your copyright notice in the Description page of Project Settings.


#include "LayerManagerHUD.h"
#include "ManagerUI.h"

void ALayerManagerHUD::RegisterDefaultLayer(const FString& name)
{
	LayersUI.Emplace(name, NewObject<ULayerUI>());
}

void ALayerManagerHUD::RegisterLayer(const FString& name, ULayerUI* layer, bool current)
{
	if (layer)
	{
		// If registering a layer that already exists prevent it and alert the user
		// Register layer is supposed to be used before PushToLayer
		if (LayersUI.Contains(name))
		{
			UE_LOG(LogManagerUI, Warning, TEXT("Warning - Tried to register layer that already exists."));
			return;
		}

		LayersUI.Emplace(name, layer);
		if (current)
			CurrentLayerID = name;
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

UE_DISABLE_OPTIMIZATION
void ALayerManagerHUD::PushToLayer(const FString& name, UUserWidget* widget)
{
	ULayerUI* layer = LayersUI.FindOrAdd(name, NewObject<ULayerUI>());
	layer->PushToStack(widget);
	CurrentLayerID = name;
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

UUserWidget* ALayerManagerHUD::PopFromCurrentLayer()
{
	return PopFromLayer(CurrentLayerID);
}

ULayerUI* ALayerManagerHUD::GetLayer(const FString& name)
{
	return (*LayersUI.Find(name));
}

UE_ENABLE_OPTIMIZATION