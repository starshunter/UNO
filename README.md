# UNO

## 三種資料結構

* Stack (牌堆)

* Queue (放玩家物件)

* List (玩家手上的牌)

### 兩種物件

* 玩家

* 牌

## 牌
我現在想到這幾種，之後可以再加

* 一般牌（顏色、數字）
* 禁止（禁止下一位出牌）
* 迴轉（反轉出排順序）
* 改顏色
* 加牌（下一個玩家抽牌）
* 改顏色和加牌

## 遊戲流程

##### 決定有幾位玩家
創幾個玩家物件放到Queue裡面

##### 初始化牌組
根據人數決定牌的數量還有每種的張數放到Stack裡面<br>
洗牌

##### 每人抽五張牌
從Stack取出5張牌放到玩家物件的List當中

##### 開始出牌
###### 玩家視角
顯示玩家所有的牌<br>
讓玩家決定要出哪張牌
###### 牌局視角
判斷玩家出的牌是否合法（顏色相同、數字相同）<br>
紀錄最新的顏色和數字<br>
如果為功能牌要對其他玩家<br>
換下一位玩家

##### 遊戲結束
玩家把牌出完遊戲就結束
