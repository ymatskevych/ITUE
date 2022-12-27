// Fill out your copyright notice in the Description page of Project Settings.


#include "ITDatabase.h"

void AITDatabase::BeginPlay()
{
	Super::BeginPlay();

	Table = NewObject<UITTable>(this);
	//Table->AddColumn<FString>(EITElementType::STRING);
	//Table->AddColumn<FString>(EITElementType::STRING);
	Table->AddColumn<int32>(EITElementType::INTEGER);
	Table->AddColumn<int32>(EITElementType::INTEGER);
	// Table->AddColumn<int32>(EITElementType::INTEGER);
	//
	//Table->AddRow<FString>(EITElementType::STRING);
	//Table->AddRow<FString>(EITElementType::STRING);
	Table->AddRow<int32>(EITElementType::INTEGER);
	Table->AddRow<int32>(EITElementType::INTEGER);
	// Table->AddRow<int32>(EITElementType::INTEGER);
}

void AITDatabase::Save()
{
	Table->Save();
}

void AITDatabase::Load()
{
	Table->Load();
}

UITTable* AITDatabase::GetTable() const
{
	return Table;
}
