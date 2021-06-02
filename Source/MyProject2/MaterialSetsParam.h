// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MaterialSetsParam.generated.h"

/**
 * 
 */
class UStaticMeshComponent;
UCLASS()
class MYPROJECT2_API UMaterialSetsParam : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "Custom Material", meta = (Keywords = "Save"))
	static void MaterialSet(UStaticMeshComponent* BotCup, UStaticMeshComponent* BotTop, UStaticMeshComponent* BotBody, UStaticMeshComponent* BotCase, UMaterialInterface* CupMat, UMaterialInterface* TopMat, UMaterialInterface* BodyMat, UMaterialInterface* CaseMat);
	
};
