// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAI.h"
#include "EngineUtils.h"

// Sets default values
AEnemyAI::AEnemyAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EnemyHealth = 50.0f;


}


// Called when the game starts or when spawned
void AEnemyAI::BeginPlay()
{
	Super::BeginPlay();


}


void AEnemyAI::EnemyTakeDamage(float Damage)
{


	if (Damage > 0)
	{

		EnemyHealth -= Damage;

	}


}


void AEnemyAI::EnemyAITakeDamage(float Damage)
{

	if (Damage > 0)

	{

		EnemyHealth -= Damage;

	}


}






// Called every frame
void AEnemyAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	Death();

	

}

void AEnemyAI::Death()
{

	if (EnemyHealth <= 0)

	{

		Destroy();

		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, TEXT("Enemy Destroyed!"));

	}


}

void AEnemyAI::InflictDamageOnCharacter(APlayer_Character* Player, float DamageToInflict)
{

	if (Player)

	{

		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Player Character Damaged!"));

		Player->TakeDamage(DamageToInflict);

	}


}

// Called to bind functionality to input
void AEnemyAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

