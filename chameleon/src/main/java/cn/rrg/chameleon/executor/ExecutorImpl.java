package cn.rrg.chameleon.executor;

import java.io.IOException;

import cn.dxl.common.posixio.Communication;
import cn.rrg.chameleon.defined.IChameleonExecutor;

/**
 * 这个类实际是个代理类，留了一个接口来初始化其中引用的实际（执行器）的实现!
 * 抽出这个类主要是为了实现将具体的类隐匿
 * 因此我们需要将初始化的必要接口留下来，此类也必须是单例!
 *
 * @author DXL
 */
public class ExecutorImpl implements IChameleonExecutor {

    private static IChameleonExecutor mExecutor;
    private static ExecutorImpl mImpl;

    public static void setExecutor(IChameleonExecutor executor) throws RuntimeException {
        if (executor == mExecutor)
            throw new RuntimeException("------->ExecutorImpl equal exception!!!");
        mExecutor = executor;
    }

    public static ExecutorImpl getInstance() {
        synchronized (ExecutorImpl.class) {
            if (mImpl == null) mImpl = new ExecutorImpl();
        }
        return mImpl;
    }

    @Override
    public boolean initExecutor(Communication com) {
        return mExecutor.initExecutor(com);
    }

    @Override
    public byte[] requestChameleon(String at, int timeout, boolean xmodemMode) {
        return mExecutor.requestChameleon(at, timeout, xmodemMode);
    }

    @Override
    public byte[] requestChameleon(int timeout, int length) {
        return mExecutor.requestChameleon(timeout, length);
    }

    @Override
    public int requestChameleon(String at, int timeout) throws IOException {
        return mExecutor.requestChameleon(at, timeout);
    }

    @Override
    public Communication getCom() {
        return mExecutor.getCom();
    }

    @Override
    public int clear(int timeout) {
        return mExecutor.clear(timeout);
    }
}
