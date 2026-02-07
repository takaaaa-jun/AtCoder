@echo off
cd /d %~dp0..

REM 1. Try to start existing container if stopped (this fixes cases where up -d fails due to conflict)
docker start atcoder >nul 2>&1

REM 2. Try to exec into the container
docker compose exec atcoder bash 2>nul
if %ERRORLEVEL% equ 0 goto :eof

REM 3. If exec failed, attempt to create/start
echo Container not usable. Starting/Recreating...
docker compose up -d
if %ERRORLEVEL% neq 0 (
    echo Conflict detected. Cleaning up old container...
    docker rm -f atcoder
    docker compose up -d
)

REM 4. Final attempt to enter
docker compose exec atcoder bash
