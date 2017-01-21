// Fill out your copyright notice in the Description page of Project Settings.

#include "TwinStickShooter.h"
#include "BaseCharacter.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
    Super::BeginPlay();
    
}

// Called every frame
void ABaseCharacter::Tick( float DeltaTime )
{
    Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//implement calculate health

void ABaseCharacter::CalculateHealth(float delta)
{
    Health += delta;

    CalculateDead();

}

//implement caculate dead
void ABaseCharacter::CalculateDead()
{
    IsDead = Health <= 0.0f;  
}

//implement post edit change property
#if WITH_EDITOR

void ABaseCharacter::PostEditChangeProperty(FPropertyChangedEvent & propertyChangedEvent)
{
    IsDead = false;
    Health = 100.0f;

    Super::PostEditChangeProperty(propertyChangedEvent);
    CalculateDead();
}

#endif