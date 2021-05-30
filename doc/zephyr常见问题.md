# Zephyr 常见问题

## [doc: confusion about dtc version #15246](https://github.com/zephyrproject-rtos/zephyr/issues/15246)

- log

```log
Assertion failed: The detected dtc version is unsupported.

      The version was found to be 1.4.5
      But the minimum supported version is 1.4.6
      See https://docs.zephyrproject.org/latest/getting_started/
      for how to use the SDK's dtc alongside a custom toolchain.
```

- solution

```shell
cd ~/zephyrproject/zephyr/
sudo rm build -r
```
