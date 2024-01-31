// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyAI.h"
#include "Projectile.generated.h"


class AEnemy;

UCLASS()
class SHOOTER_SURVIVAL_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();


	UFUNCTION(BlueprintCallable)
		void InflictDamage(float Damage, AEnemyAI* Enemy);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;




private:

	UPROPERTY(EditAnywhere, Category = "Projectile")
		class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere, Category = "Projectile")
		class UStaticMeshComponent* ProjectileMesh;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
