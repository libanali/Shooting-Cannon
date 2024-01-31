// Fill out your copyright notice in the Description page of Project Settings.


#include "SS_GameMode.h"
#include "EngineUtils.h"
#include "EnemyAI.h"




ASS_GameMode::ASS_GameMode()
{

	Spawn_Z = 27.0f;

	Seconds = 7;

	CurrentRoundNumber = 1;

	MaxRoundNumber = 3;

	RoundEnd = false;

}


void ASS_GameMode::BeginPlay()
{

	Super::BeginPlay();


	
	GetWorld()->GetTimerManager().SetTimer(GameTimerHandle, this, &ASS_GameMode::GameTimer, 1.0f, true, 1.5f);

	GetWorld()->GetTimerManager().SetTimer(SpawnTimerRound1, this, &ASS_GameMode::SpawnEnemies, FMath::RandRange(2, 3), true, 1.0f);


}



void ASS_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	/*
	AEnemyAI* EnemyAI = nullptr;

	for (TActorIterator<AEnemyAI> ActorItr(GetWorld(), AEnemyAI::StaticClass()); ActorItr; ++ActorItr)

	{


		EnemyAI = *ActorItr;

		break;

		if (GetWorld()->GetTimerManager().IsTimerActive(RoundEndTimer) && EnemyAI != nullptr)

		{

			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("YEAH!"));


		}



	}
	*/
	
}







void ASS_GameMode::SpawnEnemies()
{

	float RandX = FMath::RandRange(Spawn_X_Min, Spawn_X_Max);
	float RandY = FMath::RandRange(Spawn_Y_Min, Spawn_Y_Max);

	FVector SpawnLocation = FVector(RandX, RandY, Spawn_Z);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 90.0f);

	GetWorld()->SpawnActor(Enemy, &SpawnLocation, &SpawnRotation);

}



void ASS_GameMode::GameTimer()
{

	if (Seconds != 0)
	{

		Seconds--;

	}

	else

	{

		if (Seconds == 0 && CurrentRoundNumber == 1)

		{

			
			GetWorld()->GetTimerManager().ClearTimer(GameTimerHandle);

			GetWorld()->GetTimerManager().ClearTimer(SpawnTimerRound1);

			Round2();

			RoundEnd = true;
			
			EndOfRound();

			//NextRound();

			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("End of round"));

			CurrentRoundNumber++;

		
		}

		else if (Seconds == 0 && CurrentRoundNumber == 2)

		{

			GetWorld()->GetTimerManager().ClearTimer(GameTimerHandle);
			GetWorld()->GetTimerManager().ClearTimer(SpawnTimerRound2);

			Round3();

			RoundEnd = true;

			EndOfRound();

			//NextRound();

			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("End of round"));

			CurrentRoundNumber++;


		}

		else if (Seconds == 0 && CurrentRoundNumber == 3)

		{

			RoundEnd = true;

			//EndOfRound();

			GetWorld()->GetTimerManager().ClearTimer(GameTimerHandle);
			GetWorld()->GetTimerManager().ClearTimer(SpawnTimerRound3);
			EndOfGame();

		}

		
	}


}






void ASS_GameMode::Round2()
{

		Seconds = 10;
		GetWorld()->GetTimerManager().SetTimer(GameTimerHandle, this, &ASS_GameMode::GameTimer, 1.0f, true, 3.0f);
		GetWorld()->GetTimerManager().SetTimer(SpawnTimerRound2, this, &ASS_GameMode::SpawnEnemies, FMath::RandRange(2, 3), true, 3.0f);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Round 2 Start"));


}



void ASS_GameMode::Round3()
{

		Seconds = 17;
		GetWorld()->GetTimerManager().SetTimer(GameTimerHandle, this, &ASS_GameMode::GameTimer, 1.0f, true, 3.0f);
		GetWorld()->GetTimerManager().ClearTimer(SpawnTimerRound2);
		GetWorld()->GetTimerManager().SetTimer(SpawnTimerRound3, this, &ASS_GameMode::SpawnEnemies, FMath::RandRange(1, 2), true, 3.0f);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Round 3 Start"));


}





void ASS_GameMode::EndOfGame()
{



		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Complete"));
		GetWorld()->GetTimerManager().ClearTimer(SpawnTimerRound3);


}

void ASS_GameMode::EndOfRound()
{

	RoundEnd = true;

	

		GetWorld()->GetTimerManager().SetTimer(RoundEndTimer, this, &ASS_GameMode::EndOfRound, 1.0f, true, 3.0f);
		GetWorld()->GetTimerManager().SetTimer(TimeClearHanlde, this, &ASS_GameMode::NextRound, 3.0f, false);
	
}



void ASS_GameMode::NextRound()
{


	RoundEnd = false;


	

		GetWorld()->GetTimerManager().ClearTimer(RoundEndTimer);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Next Round!"));


}
