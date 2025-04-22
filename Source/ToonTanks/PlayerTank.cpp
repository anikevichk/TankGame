// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Components/CapsuleComponent.h"

APlayerTank::APlayerTank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Arm Component"));
	ArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComponent->SetupAttachment(ArmComponent);
    
}

void APlayerTank::BeginPlay()
{
	Super::BeginPlay();

    PlayerControllerRef =Cast<APlayerController>(GetController());
}

void APlayerTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    FHitResult HitResult;
    if(PlayerControllerRef){
        PlayerControllerRef->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, HitResult);
        // DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0, 12, FColor::Red, false, -1.f);
        ATankPawn::RotateTurret(HitResult.ImpactPoint);
    }
}


void APlayerTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
   Super::SetupPlayerInputComponent(PlayerInputComponent);

   PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerTank::Move);
   PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APlayerTank::Turn);
   PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &APlayerTank::Fire);
}

void APlayerTank::Move(float value){
    double LocalDeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);

    FVector DeltaLocation = FVector::ZeroVector;
    DeltaLocation.X = value * speed * LocalDeltaTime;
    AddActorLocalOffset(DeltaLocation, true);
}

void APlayerTank::Turn(float value){
    double LocalDeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);

    FRotator DeltaRotation = FRotator::ZeroRotator;
    DeltaRotation.Yaw = value * turnSpeed * LocalDeltaTime;
    AddActorLocalRotation(DeltaRotation, true);
}
