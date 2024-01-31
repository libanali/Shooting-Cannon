// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_Character.h"
#include "Projectile.h"

// Sets default values
APlayer_Character::APlayer_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	MaxHealth = 100.0f;
	CurrentHealth = MaxHealth;

	bDead = false;


}





void APlayer_Character::TakeDamage(float Damage)
{

	if (Damage > 0)
	{

		CurrentHealth -= Damage;
		CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0, MaxHealth);
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, TEXT("Player Damaged!"));

	}


	if (CurrentHealth <= 0)

	{

		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, TEXT("Game Over!"));

		PlayerDeath();

	}

}



// Called when the game starts or when spawned
void APlayer_Character::BeginPlay()
{
	Super::BeginPlay();
	

}

void APlayer_Character::MoveForward(float Axis)
{

	if (!bDead)

	{

		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Axis);

	}

}


void APlayer_Character::MoveRight(float Axis)
{

	if (!bDead)

	{
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Axis);

	}
}



void APlayer_Character::PlayerDeath()
{

	//APlayer_Character::GetCharacterMovement()->SetMovementMode(MOVE_None);

	bDead = true;
	APlayer_Character::DisableInput(GetWorld()->GetFirstPlayerController());
	//Destroy(true);

}



// Called every frame
void APlayer_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentHealth = FMath::Clamp(CurrentHealth, 0, MaxHealth);


}

// Called to bind functionality to input
void APlayer_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	PlayerInputComponent->BindAxis("MoveRight", this, &APlayer_Character::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayer_Character::MoveForward);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Look Up", this, &APawn::AddControllerPitchInput);


	//PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &APlayer_Character::Shoot);



}

