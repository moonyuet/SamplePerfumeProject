// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CameraPawn.generated.h"

class USpringArmComponent;
class UCameraComponent;
class APlayerController;

UCLASS()
class MYPROJECT2_API ACameraPawn : public APawn
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;
	UPROPERTY()
	APlayerController* PlayerController;
	UPROPERTY(EditAnywhere)
	float PanSpeed = 4;
	void CalculateYawInput(float Value);
	void CalculatePitchInput(float Value);
	void WheelAxisInput(float Value);
	void SetRotation();
	void SetMouseCursor();
	// Sets default values for this pawn's properties
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	ACameraPawn();

	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};