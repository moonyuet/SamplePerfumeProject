// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 100;
	SpringArm->bUsePawnControlRotation = true;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	FVector CamTrans = FVector(-150, 0, 0);
	Camera->AddRelativeLocation(CamTrans);
	
}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = Cast<APlayerController>(GetController());
}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("X Control", this, &ACameraPawn::CalculateYawInput);
	PlayerInputComponent->BindAxis("Y Control", this, &ACameraPawn::CalculatePitchInput);

	PlayerInputComponent->BindAxis("Wheel Axis", this, &ACameraPawn::WheelAxisInput);
}
void ACameraPawn::CalculateYawInput(float Value)
{
	AddControllerYawInput(Value);
	SetMouseCursor();
	SetRotation();
	
}

void ACameraPawn::CalculatePitchInput(float Value)
{
	AddControllerPitchInput(Value);
	SetMouseCursor();
}

void ACameraPawn::SetRotation()

{
	Controller = UGameplayStatics::GetPlayerController(GetController(), 0);
	FRotator Transform = Controller->GetControlRotation();
	Controller->SetControlRotation(Transform);
	return;

}
void ACameraPawn::SetMouseCursor()
{
	PlayerController->bShowMouseCursor = true;
}

void ACameraPawn::WheelAxisInput(float Value)
{
		float XValue = Value * PanSpeed;
		FVector CameraDir = FVector(XValue, 0, 0);
		Camera->AddRelativeLocation(CameraDir);
}