// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"	
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SimpleSetLinearCol.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API USimpleSetLinearCol : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		UFUNCTION(BlueprintCallable)
		static void SimpleSetLinear(FLinearColor GetMetalCol, FLinearColor GetGlassCol, FLinearColor& MetalColOut, FLinearColor& GlassColorOut);
};
