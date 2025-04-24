// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "Projectile.h"
#include "DrawDebugHelpers.h"

// Sets default values
ATankPawn::ATankPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}



void ATankPawn::RotateTurret(FVector LookAtTarget){
	FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();
	// FRotator LookAtRotation = ToTarget.Rotation();
	// LookAtRotation.Roll = 0.f;
	// LookAtRotation.Pitch = 0.f;
	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);

	TurretMesh->SetWorldRotation(
		FMath::RInterpTo(
			TurretMesh->GetComponentRotation(), 
			LookAtRotation, 
			UGameplayStatics::GetWorldDeltaSeconds(this), 
			15.f));
}

void ATankPawn::Fire(){
    // DrawDebugSphere(GetWorld(), ProjectileSpawnPoint->GetComponentLocation(), 10.0, 12, FColor::Red, false, 3.f);
	FVector Location = ProjectileSpawnPoint->GetComponentLocation();
	FRotator Rotator = ProjectileSpawnPoint->GetComponentRotation();

	auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Location, Rotator);
	Projectile->SetOwner(this);
}

void ATankPawn::HandleDestruction(){
	
}