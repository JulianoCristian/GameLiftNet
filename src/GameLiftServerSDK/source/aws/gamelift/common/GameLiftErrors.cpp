/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
#include <aws/gamelift/common/GameLiftErrors.h>

using namespace Aws::GameLift;

GameLiftError::GameLiftError() {}

GameLiftError::GameLiftError(GAMELIFT_ERROR_TYPE errorType)
    : m_errorType(errorType)
    , m_errorName(::GameLiftError::GetDefaultNameForErrorType(errorType))
    , m_errorMessage(::GameLiftError::GetDefaultMessageForErrorType(errorType))
{}

GameLiftError::GameLiftError(GAMELIFT_ERROR_TYPE errorType, std::string errorName, std::string message) :
m_errorType(errorType), m_errorName(errorName), m_errorMessage(message) {}

GameLiftError::GameLiftError(const GameLiftError& rhs) :
m_errorType(rhs.GetErrorType()), m_errorName(rhs.GetErrorName()), m_errorMessage(rhs.GetErrorMessage()) {}

GameLiftError::~GameLiftError() {}

std::string GameLiftError::GetDefaultNameForErrorType(GAMELIFT_ERROR_TYPE errorType)
{
    switch (errorType) {
    case GAMELIFT_ERROR_TYPE::ALREADY_INITIALIZED:
        return "Already Initialized";
    case GAMELIFT_ERROR_TYPE::FLEET_MISMATCH:
        return "Fleet mismatch.";
    case GAMELIFT_ERROR_TYPE::GAMELIFT_CLIENT_NOT_INITIALIZED:
        return "GameLift client not initialized.";
    case GAMELIFT_ERROR_TYPE::GAMELIFT_SERVER_NOT_INITIALIZED:
        return "GameLift server not initialized.";
    case GAMELIFT_ERROR_TYPE::GAME_SESSION_ENDED_FAILED:
        return "Game session failed.";
    case GAMELIFT_ERROR_TYPE::GAME_SESSION_NOT_READY:
        return "Game session not activated.";
    case GAMELIFT_ERROR_TYPE::GAME_SESSION_READY_FAILED:
        return "Game session failed.";
    case GAMELIFT_ERROR_TYPE::INITIALIZATION_MISMATCH:
        return "Initialization mismatch.";
    case GAMELIFT_ERROR_TYPE::NOT_INITIALIZED:
        return "Not Initialized";
    case GAMELIFT_ERROR_TYPE::NO_TARGET_ALIASID_SET:
        return "No target aliasId set.";
    case GAMELIFT_ERROR_TYPE::NO_TARGET_FLEET_SET:
        return "No target fleet set.";
    case GAMELIFT_ERROR_TYPE::PROCESS_ENDING_FAILED:
        return "Process ending failed.";
    case GAMELIFT_ERROR_TYPE::PROCESS_NOT_ACTIVE:
        return "Process not activated.";
    case GAMELIFT_ERROR_TYPE::PROCESS_NOT_READY:
        return "Process not ready.";
    case GAMELIFT_ERROR_TYPE::PROCESS_READY_FAILED:
        return "Process ready failed.";
    case GAMELIFT_ERROR_TYPE::SDK_VERSION_DETECTION_FAILED:
        return "Could not detect SDK version.";
    case GAMELIFT_ERROR_TYPE::SERVICE_CALL_FAILED:
        return "Service call failed.";
    case GAMELIFT_ERROR_TYPE::STX_CALL_FAILED:
        return "STX call failed.";
    case GAMELIFT_ERROR_TYPE::STX_INITIALIZATION_FAILED:
        return "STX Initialization Failed.";
    case GAMELIFT_ERROR_TYPE::UNEXPECTED_PLAYER_SESSION:
        return "Unexpected player session.";
    default:
        return "Uknown Error";
    }
}

std::string GameLiftError::GetDefaultMessageForErrorType(GAMELIFT_ERROR_TYPE errorType)
{
    switch (errorType) {
    case GAMELIFT_ERROR_TYPE::ALREADY_INITIALIZED:
        return  "GameLift has already been initialized. You must call Destroy() before reinitializing the client or server.";
    case GAMELIFT_ERROR_TYPE::FLEET_MISMATCH:
        return "The Target fleet does not match the request fleet. Make sure GameSessions and PlayerSessions belong to your target fleet.";
    case GAMELIFT_ERROR_TYPE::GAMELIFT_CLIENT_NOT_INITIALIZED:
        return "The GameLift client has not been initialized. Please call SetTargetFleet or SetTArgetAliasId.";
    case GAMELIFT_ERROR_TYPE::GAMELIFT_SERVER_NOT_INITIALIZED:
        return "The GameLift server has not been initialized. Please call InitSDK.";
    case GAMELIFT_ERROR_TYPE::GAME_SESSION_ENDED_FAILED:
        return "The GameSessionEnded invocation failed.";
    case GAMELIFT_ERROR_TYPE::GAME_SESSION_NOT_READY:
        return "The Game session associated with this server was not activated.";
    case GAMELIFT_ERROR_TYPE::GAME_SESSION_READY_FAILED:
        return "The GameSessionReady invocation failed.";
    case GAMELIFT_ERROR_TYPE::INITIALIZATION_MISMATCH:
        return "The current call does not match the initialization state. Client calls require a call to Client::Initialize(), and Server calls require Server::Initialize(). Only one may be active at a time.";
    case GAMELIFT_ERROR_TYPE::NOT_INITIALIZED:
        return  "GameLift has not been initialized! You must call Client::Initialize() or Server::InitSDK() before making GameLift calls.";
    case GAMELIFT_ERROR_TYPE::NO_TARGET_ALIASID_SET:
        return "The aliasId has not been set. Clients should call SetTargetAliasId() before making calls that require an alias.";
    case GAMELIFT_ERROR_TYPE::NO_TARGET_FLEET_SET:
        return "The target fleet has not been set. Clients should call SetTargetFleet() before making calls that require a fleet.";
    case GAMELIFT_ERROR_TYPE::PROCESS_ENDING_FAILED:
        return "ProcessEnding call to GameLift failed.";
    case GAMELIFT_ERROR_TYPE::PROCESS_NOT_ACTIVE:
        return "The process has not yet been activated.";
    case GAMELIFT_ERROR_TYPE::PROCESS_NOT_READY:
        return "The process has not yet been activated by calling ProcessReady(). Processes in standby cannot receive StartGameSession callbacks.";
    case GAMELIFT_ERROR_TYPE::PROCESS_READY_FAILED:
        return "ProcessReady call to GameLift failed.";
    case GAMELIFT_ERROR_TYPE::SDK_VERSION_DETECTION_FAILED:
        return "Could not detect SDK version.";
    case GAMELIFT_ERROR_TYPE::SERVICE_CALL_FAILED:
        return "An AWS service call has failed. See the root cause error for more information.";
    case GAMELIFT_ERROR_TYPE::STX_CALL_FAILED:
        return "An internal call to the STX server backend component has failed.";
    case GAMELIFT_ERROR_TYPE::STX_INITIALIZATION_FAILED:
        return "The STX server backend component has failed to initialize.";
    case GAMELIFT_ERROR_TYPE::UNEXPECTED_PLAYER_SESSION:
        return "The player session was not expected by the server. Clients wishing to connect to a server must obtain a PlayerSessionID from GameLift by creating a player session on the desired server's game instance.";
    default:
        return "An unexpected error has occurred.";
    }
}