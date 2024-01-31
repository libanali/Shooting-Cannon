// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "SS_GameMode.generated.h"

/**
 * 
 */

class AEnemyAI;

UCLASS()
class SHOOTER_SURVIVAL_API ASS_GameMode : public AGameMode
{
	GENERATED_BODY()


	ASS_GameMode();

protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
		int Seconds;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Round")
		int32 MaxRoundNumber;


	UPROPERTY()
		class APlayer_Character* PlayerChar;


	UFUNCTION(BlueprintCallable)
		void SpawnEnemies();


private:

	//UFUNCTION(BlueprintCallable)
	//	void SpawnEnemies();

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> Enemy;

	UPROPERTY(EditAnywhere)
		float Spawn_X_Min;

	UPROPERTY(EditAnywhere)
		float Spawn_X_Max;

	UPROPERTY(EditAnywhere)
		float Spawn_Y_Min;

	UPROPERTY(EditAnywhere)
		float Spawn_Y_Max;

	float Spawn_Z;





	UFUNCTION()
		void EndOfGame();


	UFUNCTION()
		void EndOfRound();

	UFUNCTION()
		void NextRound();


	void Round2();
	void Round3();



	

	UFUNCTION()
		void GameTimer();




	//void ResetGameTimer();



		FTimerHandle SpawnTimerRound1;

		FTimerHandle SpawnTimerRound2;

		FTimerHandle SpawnTimerRound3;

		FTimerHandle GameTimerHandle;

		//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer")
		//FTimerHandle RoundEndTimer;

		FTimerHandle TimeClearHanlde;



public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Round")
		int32 CurrentRoundNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Round")
		bool RoundEnd;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer")
		FTimerHandle RoundEndTimer;


	
};
