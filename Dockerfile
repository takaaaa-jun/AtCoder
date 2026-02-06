# syntax=docker/dockerfile:1
# ベースイメージをNode.js (Debian Bookwormベース) に変更
# これにより GCC 12.2.0 が利用可能になり、AtCoderのジャッジ環境に近づきます
FROM node:lts-bookworm

# 対話モード防止とタイムゾーン設定
ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Asia/Tokyo

WORKDIR /app

# 必要なパッケージのインストール
# time: 実行時間計測, tree: ディレクトリ表示, gdb: デバッグ用
RUN apt-get update && apt-get install -y \
    g++ \
    gdb \
    python3 \
    python3-pip \
    git \
    curl \
    wget \
    time \
    tzdata \
    tree \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# AtCoder Library (ACL) のインストール
RUN git clone https://github.com/atcoder/ac-library.git /lib/ac-library
ENV CPLUS_INCLUDE_PATH=/lib/ac-library

# atcoder-cli (acc) のインストール
RUN npm install -g atcoder-cli

# online-judge-tools (oj) のインストール
# Debian Bookworm以降は --break-system-packages が必要
RUN pip3 install online-judge-tools --break-system-packages

# コンテナがすぐ終了しないように待機
CMD ["tail", "-f", "/dev/null"]