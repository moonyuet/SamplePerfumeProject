// Fill out your copyright notice in the Description page of Project Settings.


#include "ProductActorBase.h"

// Sets default values
AProductActorBase::AProductActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Root"));
	RootComponent = DefaultSceneRoot;

	BottleCup = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bottle Cup"));
	BottleCup->SetupAttachment(RootComponent);
	
	BottleTop = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bottle Top"));
	BottleTop->SetupAttachment(RootComponent);

	BottleBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bottle Body"));
	BottleBody->SetupAttachment(RootComponent);

	BottleTube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bottle Tube"));
	BottleTube->SetupAttachment(RootComponent);

	BottleCase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bottle Case"));
	BottleCase->SetupAttachment(RootComponent);

}
