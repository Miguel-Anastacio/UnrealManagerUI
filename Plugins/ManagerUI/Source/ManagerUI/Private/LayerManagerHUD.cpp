// Fill out your copyright notice in the Description page of Project Settings.


#include "LayerManagerHUD.h"
#include "ManagerUI.h"
#include "LayerUI.h"

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
		ULayerUI** existingLayer = LayersUI.Find(name);
		if (existingLayer)
		{
			(*existingLayer)->Type = layer->Type;
			UE_LOG(LogManagerUI, Warning, TEXT("Tried to register layer that already exists."));

			return;
		}

		LayersUI.Emplace(name, layer);
		if (current)
			CurrentLayerID = name;
	}
	else
	{
		UE_LOG(LogManagerUI, Error, TEXT("Tried to register invalid layer"));
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
	ULayerUI* layer;
	TArray<ULayerUI*> layersValue;
	// if it already exists
	// save data remove it, generate array from map, and add layer again
	if (LayersUI.RemoveAndCopyValue(name, layer))
	{
		LayersUI.GenerateValueArray(layersValue);
		LayersUI.Add(name, layer);
	}
	else
	{
		LayersUI.GenerateValueArray(layersValue);
	}

	// layersValue now contains all layers except the one we are pushing to

	// did not find a layer so add a generic one
	if (!IsValid(layer))
	{
		layer = NewObject<ULayerUI>();
		LayersUI.Add(name, layer);
	}

	layer->PushToStack(widget);
	// pass all other layers 
	layer->OnWidgetPushedOthers(layersValue);

	CurrentLayerID = name;
}
UUserWidget* ALayerManagerHUD::PopFromLayer(const FString& name)
{
	ULayerUI* layer;
	TArray<ULayerUI*> layersValue;
	// if it already exists
	// save data remove it, generate array from map, and add layer again
	if (LayersUI.RemoveAndCopyValue(name, layer))
	{
		LayersUI.GenerateValueArray(layersValue);
		LayersUI.Add(name, layer);
	}
	else
	{
		LayersUI.GenerateValueArray(layersValue);
	}

	if (layer)
	{
		layer->OnWidgetPoppedOthers(layersValue);
		return layer->PopFromStack();
	}
	
	return nullptr;
}

UUserWidget* ALayerManagerHUD::PopFromCurrentLayer()
{
	return PopFromLayer(CurrentLayerID);
}

void ALayerManagerHUD::ClearAllLayers()
{
	for (auto& elem : LayersUI)
	{
		elem.Value->ClearStack();
	}
	LayersUI.Empty();
}

ULayerUI* ALayerManagerHUD::GetLayer(const FString& name)
{
	return (*LayersUI.Find(name));
}

UE_ENABLE_OPTIMIZATION