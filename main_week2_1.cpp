#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    //ü�� ����
    int maxHealth = health; //�ִ� ü�·� ����
    int currentHealth = health; //���� ü��

    //��ų��
    int bandageDuration = bandage[0]; //�ش� ���� ���� �ð�
    int healAmount = bandage[1]; //�ʴ� ȸ����
    int bonusHeal = bandage[2]; //���� ���� �� �߰� ȸ����

    //���� ���� �ʿ��� ���
    int time = attacks[attacks.size() - 1][0];
    int bandageContinue = 0; //���� �ش� ���� ���� �ð�
    int lastAttackIndex = 0; //������ ���� �ε���

    for (int t = 0; t <= time; t++) {
        if (attacks[lastAttackIndex][0] == t) {
            currentHealth -= attacks[lastAttackIndex][1]; // ü�� ����
            //���̴����Ұ��
            if (currentHealth <= 0)
                return -1;
            lastAttackIndex++; //���� �������� �̵�
            bandageContinue = 0; //���� ���� �ð� �ʱ�ȭ
        }
        else {

            //�ش� ���� ������
            if (bandageContinue <= bandageDuration) {
                currentHealth += healAmount; //ü�� ȸ��
                bandageContinue++; //���� �ð� ����
            }
            //�ش� ���� �Ϸ�
            if (bandageContinue == bandageDuration) {
                currentHealth += bonusHeal; //�߰� ü�� ����
                bandageContinue = 0;
            }
            // ü���� �ִ� ü���� ���� �ʵ��� ����
            if (currentHealth > maxHealth) {
                currentHealth = maxHealth;
            }

        }
    }

    return currentHealth;
}
