// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ScreenShot.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UScreenShot : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
		UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "Save"))
		static bool HighResScreenShot(int width, int height, FString filename, bool SetAlpha);
	
};
