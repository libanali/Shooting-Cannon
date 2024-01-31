// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EnemyHealth = 40.0f;



}

void AEnemy::EnemyTakeDamage(float Damage)
{

	if (Damage > 0)
	{

		EnemyHealth -= Damage;

	}

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemy::Death()
{

	if (EnemyHealth <= 0)

	{

		Destroy();

		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, TEXT("Enemy Destroyed!"));

	}


}

void AEnemy::InflictDamageOnCharacter(APlayer_Character* Player, float DamageToInflict)
{

	if (Player)

	{

		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Player Character Damaged!"));

		Player->TakeDamage(DamageToInflict);

	}


}



// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Death();
}

