# 51 单片机数码管（74HC138 位选）学习笔记：switch 分支、动态扫描、消影、TM1640

> 目标：用 8051（REGX52）驱动多位数码管。硬件常见结构为：  
> - 位选：P2.2/P2.3/P2.4 → 74HC138（三八译码器）→ 8 位位选  
> - 段选：P0 → a,b,c,d,e,f,g,dp（段码）

---

## 1. 基础显示函数 `NieXie(Location, number)` 的职责

- `Location`：选择当前点亮的“第几位”（位选）
- `number`：选择该位显示的数字（段选）

典型流程（动态扫描的一个“切片”）应为：
1) 消隐（关段，防止切位瞬态重影）
2) 切换位选
3) 输出段码
4) 保持点亮一段很短时间（1ms 级）
5) 再次消隐，为下一位切换做准备

---

## 2. 典型错误 1：`case1:` 写法导致“无论 Location 都只亮同一位”

### 现象
调用 `NieXie(5,0)` 或 `NieXie(2,0)`，结果都是同一位亮。

### 根因（非常关键）
在 C 语言里必须写成 `case 1:`、`case 2:`。  
`case1:` 会被当成普通的 **label（标号）**，不是 switch 的分支，因此 `switch(Location)` 不能跳转到对应分支，代码会从 switch 内第一句开始执行，造成“永远执行第一段”。

### 正确写法示例
```c
switch(Location)
{
    case 1: /*...*/ break;
    case 2: /*...*/ break;
    ...
}
#include <REGX52.H>

unsigned char NieTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void Delay(unsigned int xms)  // 12MHz 近似 1ms 延时
{
    unsigned char i, j;
    while(xms--)
    {
        i = 2;
        j = 239;
        do { while(--j); } while(--i);
    }
}

void NieXie(unsigned char Location, unsigned char number)
{
    // ① 先消隐（关段）——防止切位瞬态出现重影
    P0 = 0x00;

    // ② 切位选（根据你的硬件连线可能需要调整顺序/倒序）
    switch(Location)
    {
        case 8: P2_4=1; P2_3=1; P2_2=1; break;
        case 7: P2_4=1; P2_3=1; P2_2=0; break;
        case 6: P2_4=1; P2_3=0; P2_2=1; break;
        case 5: P2_4=1; P2_3=0; P2_2=0; break;
        case 4: P2_4=0; P2_3=1; P2_2=1; break;
        case 3: P2_4=0; P2_3=1; P2_2=0; break;
        case 2: P2_4=0; P2_3=0; P2_2=1; break;
        case 1: P2_4=0; P2_3=0; P2_2=0; break;
        default: break;
    }

    // ③ 上段码
    P0 = NieTable[number];

    // ④ 保持点亮时间（影响亮度）
    Delay(1);

    // ⑤ 再消隐，为下一位切换做准备
    P0 = 0x00;
}
