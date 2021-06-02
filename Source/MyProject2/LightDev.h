// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProductActorBase.h"
#include "LightDev.generated.h"

/**
 * 
 */
class UPointLightComponent;
UCLASS()
class MYPROJECT2_API ALightDev : public AProductActorBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPointLightComponent* Keylight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPointLightComponent* Filllight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPointLightComponent* Sidelight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPointLightComponent* LeftLight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPointLightComponent* KickLight;

public:
	ALightDev();

	
};
