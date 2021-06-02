// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProductActorBase.generated.h"


UCLASS()
class MYPROJECT2_API AProductActorBase : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	USceneComponent* DefaultSceneRoot;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* BottleCup;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* BottleTop;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* BottleBody;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* BottleCase;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* BottleTube;

public:	
	// Sets default values for this actor's properties
	AProductActorBase();

};
