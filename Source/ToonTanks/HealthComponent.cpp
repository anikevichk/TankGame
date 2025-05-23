// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "TanksGameMode.h"
#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::GetDamage);	
	GameMode = Cast<ATanksGameMode>(UGameplayStatics::GetGameMode(this));
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::GetDamage(
	AActor* DamagedActor, float Damage, const UDamageType* DamageType, 
	AController* Instigator, AActor* DamageCauser){
		if (Damage >= 0.f){
		CurrentHealth-=Damage;
		UE_LOG(LogTemp, Display, TEXT("Current health: %f"), CurrentHealth);

		if(CurrentHealth <= 0 && GameMode){
			GameMode->ActorDied(DamagedActor);
		}
	}

}