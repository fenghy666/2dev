package onbon.bx05.tutorial.server;

import onbon.bx05.Bx5GEnv;
import onbon.bx05.Bx5GScreen;
import onbon.bx05.Bx5GServer;
import onbon.bx05.Bx5GServerListener;

public class SimpleCommand {

    public static void main(String[] args) throws Exception {
        // ��ʼ�� Bx5G API �h���������ϵ�y���ӕr�Ȉ��С�
        Bx5GEnv.initial("log.properties");

        // ���ӷ��՚�ģʽ��8001 PORT ��ͨ�첺��
        Bx5GServer server = new Bx5GServer("TEST", 8001);

        // �����O���B��O ��ʽ
        server.addListener(new ConnectionListener());

        // ���ӷ�����
        server.start();
        System.out.println("waiting...");

        Thread.sleep(120000);

        // �Kֹ������
        server.stop();
        System.out.println("done!");
    }

    public static class ConnectionListener implements Bx5GServerListener {

        @Override
        public void connected(String socketId, String netId, Bx5GScreen screen) {
            // ������Ļ�B���r�����l�����¼���
            System.out.println(socketId + " online:" + netId);
            System.out.println("ping:     " + screen.ping());						// PING �O��
            System.out.println("status:   " + screen.checkControllerStatus());		// ȡ�ÿ�������B
            System.out.println("frimware: " + screen.checkFirmware());				// �z���g�w�汾
            System.out.println("id:       " + screen.readControllerId());			// �xȡ��������̖

            // TODO: ���� screen �YӍ�������_�lϵ�y���M���B��������P����
        }

        @Override
        public void disconnected(String socketId, String controllerAddr, Bx5GScreen screen) {
            // ������Ļ�ྀ�r�����l�����¼���

            // TODO: ���� screen �YӍ�������_�lϵ�y���M�Дྀ̎��
        }
    }
}
