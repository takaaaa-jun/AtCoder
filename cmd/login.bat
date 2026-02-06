@echo off
cd /d %~dp0..

REM Try to exec into the running container
docker compose exec atcoder bash 2>nul
if %ERRORLEVEL% equ 0 goto :eof

REM If exec failed, it likely means the container isn't running.
echo Container is not running. Starting it up...
docker compose up -d
docker compose exec atcoder bash
