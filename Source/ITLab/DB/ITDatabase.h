// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Table/ITTable.h"
#include "ITDatabase.generated.h"

UCLASS()
class ITLAB_API AITDatabase : public AActor
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	void Save();
	void Load();

	UITTable* GetTable() const;
	
private:

	UPROPERTY()
	UITTable* Table;
};
