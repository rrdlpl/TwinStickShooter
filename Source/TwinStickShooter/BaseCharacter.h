// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Blueprintable)
class TWINSTICKSHOOTER_API ABaseCharacter : public ACharacter
{
    GENERATED_BODY()

public: 

    //Make health property;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Character")
        float Health = 100.0f;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Base Character")
        bool IsDead = false;

    //Calculate dead function
    virtual void CalculateDead();

    //Calculate health function
    UFUNCTION(BlueprintCallable, Category = "Base Character")
        virtual void CalculateHealth(float delta);

#if WITH_EDITOR
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

public:
    // Sets default values for this character's properties
    ABaseCharacter();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
    // Called every frame
    virtual void Tick( float DeltaSeconds ) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    
    
};
