# AtCoderの問題を解くための環境を整えるスクリプト

## 使い方

### Dockerの起動
```bash
docker compose up -d
```

### Dockerの停止
```bash
docker compose down
```

### 競技プログラミングの時に使用するコマンド
```bash
source /app/atcoder_utils.sh
mkc abc300 # ABCの番号を指定
cptest # コンパイルしてテストを実行
next # 次の問題に移動
prev # 前の問題に戻る
goto b # b問題に移動
home # Moved to: /app/src/atcoder/abc
```

### GithubのPUSH
```bash
git add .
git commit -m "comment"
git push origin main
```
