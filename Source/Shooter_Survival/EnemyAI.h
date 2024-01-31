// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Player_Character.h"
#include "EnemyAI.generated.h"



UCLASS()
class SHOOTER_SURVIVAL_API AEnemyAI : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyAI();





protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UFUNCTION(BlueprintCallable)
		void EnemyTakeDamage(float Damage);


	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void Death();

	UFUNCTION(BlueprintCallable)
		void InflictDamageOnCharacter(APlayer_Character* Player, float DamageToInflict);

	UFUNCTION(BlueprintCallable)
		void EnemyAITakeDamage(float Damage);


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float EnemyHealth;


	//UPROPERTY()
		//class ASS_GameMode* SS_GameMode;



	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
