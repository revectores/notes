##### 双序列比对算法

BLAST



全局比对vs局部比对



空位罚分：对所有空位扣相同的分数/对开启空位扣较多的分数, 对后期的延伸扣较少的分数

好的算法：尽可能多的匹配，尽可能少的空位，插入任意多的空位可能会产生较大的分数，但找到的并不一定是真正的相似序列

$W_x=g+r(x-1)$

$空位总记分=空位开放罚分+空位扩展罚分\times(序列长度-1)$

无空位$O(n^2)$, 允许空位$O(2^{2n})$, 走DP可以将时间控制在多项式时间内.

替代矩阵BLOSUM62, 参数设定$g=11, r=1$ (BLAST默认的矩阵)

算法设计上较为复杂，常常仍然使用正比例罚分

DP 01背包问题



常用比对方法 全局Needleman-Wunsch 局部Smith-Waterman

Needleman-Wunsch

FASTA  BLAST的基本思想  启发式算法，不能保证搜索到最优解  时间复杂度<$O(n)$



BLASTP		氨基酸序列在蛋白数据库中找到相似序列

PSI-BLAST	比BLASTP灵敏度更高，适用于发现远亲物种的相似蛋白/某个蛋白的新家族成员

PHI-BLAST	仅仅找出那些查询序列中含有的特殊模式对齐

迭代搜索：先使用BLASTP搜索，再将结果放进PSI-PLAST中筛选，能够发现相似性非常低的同源序列，但有可能导致假阳性的结果

用常规的BLASTP搜索数据库->构建多序列比对，为每个比对序列建立一个专门的序列谱(profile)->利用profile搜索原来的数据库->检验比对后每个匹配的统计显著性

PHI-BLAST允许使用正则表达式进行模式匹配  同时匹配同源序列



打分矩阵设计

DNA打分矩阵

等价矩阵  BLAST矩阵  转移矩阵（转换-颠换矩阵）

等价矩阵：相同碱基+1 不同碱基0

BLAST矩阵：相同碱基+5 不同碱基-4

转移矩阵：相同碱基+1 转换-1 颠换-5  演化过程中转换概率>颠换概率



氨基酸打分矩阵

等价矩阵

氨基酸突变代价矩阵GCM：根据氨基酸发生变化所需要的密码子变化，若变化一个碱基则替换代价为1，若变化两个碱基则替换代价为2

疏水矩阵：根据氨基酸突变前后疏水性变化得到得分矩阵，若变化不大则评分较高，变化较大的评分较低

上述两个矩阵比等价矩阵更合理一些，但准确性仍然不足

PAM矩阵（Point Accepted Mutation）

PAM Accepted Point Mutation 可接受的点突变 氨基酸的改变并不影响蛋白质的功能 1PAM是一个进化的变异单位. 意为1%的氨基酸改变.

PAM250 Matrix

各个氨基酸本身的替换频率最大

本身的替换频率越高意味着该氨基酸在自然界中较少

正值表示氨基酸之间的替换频率大，负值表示氨基酸之间的替换频率小 

PAM250  15~30%的序列相似性

PAM120  40%的序列相似性

PAM80    50%

PAM60    60%

遍历尝试

存在的问题：氨基酸的打分矩阵 不关心核酸

演化模型的构建需要系统发育树的分析，存在循环论证的问题

数据集很小



BLOSUM矩阵（Blocks Amino Acid Substitution Matries）

BLOCK：蛋白质家族保守的一段AA，无GAP，一般包括几十个～上百个AA.

Prosite家族：至少有一个BLOCK存在于该家族的所有蛋白质序列中

分析>500个Prosite家族之后，BLOSUM62 序列的平均相似性为62%的矩阵所构建的打分矩阵

用于产生矩阵的蛋白质家族及多肽链数目，BLOSUM比PAM大约多20倍，PAM家族内成员相比，然后把所有家族中所对某种氨基酸的比较结果加和产生PAM-1, PAM-1自乘n次得到PAM-n.

Which Matrix to use?

Close relationships-> Low PAM, high Blosum

Distant relationships-> High PAM, low Blosum

Less divergent BLOSUM 80 PAM 1

Mid BLOSUM 62 PAM 120

More divergent BLOSUM 45 PAM 250

BLOSUM常常效果更好