# syntax=docker/dockerfile:1
FROM node:lts-bookworm

# インタラクティブモードにならないようにする
ARG DEBIAN_FRONTEND=noninteractive

# タイムゾーンを日本に設定
ENV TZ=Asia/Tokyo

WORKDIR /app

# 起動シェルをshからbashに変更
SHELL ["/bin/bash", "-c"]

# パッケージなど
RUN apt update && \
    apt install -y \
    time \
    tzdata \
    tree \
    git \
    curl \
    gcc \
    g++ \
    gdb \
    python3 \
    python3-pip

# C++でAtCoder Library(ACL)を使えるようにする
RUN git clone https://github.com/atcoder/ac-library.git /lib/ac-library
ENV CPLUS_INCLUDE_PATH /lib/ac-library

# atcoder-cliのインストール
RUN npm install -g atcoder-cli@2.2.0

# ojのインストール
# システムのPython環境に入れるため --break-system-packages を付与
RUN pip install online-judge-tools==11.5.1 --break-system-packages