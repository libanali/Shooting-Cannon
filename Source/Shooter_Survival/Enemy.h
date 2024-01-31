// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Player_Character.h"
//#include "Projectile.h"
#include "Enemy.generated.h"


class AProjectile;

UCLASS()
class SHOOTER_SURVIVAL_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float EnemyHealth;

	UFUNCTION(BlueprintCallable)
		void EnemyTakeDamage(float Damage);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
		void Death();

	UFUNCTION(BlueprintCallable)
		void InflictDamageOnCharacter(APlayer_Character* Player, float DamageToInflict);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
