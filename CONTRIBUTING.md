# CONTRIBUTION

- 謝謝點開我，如果您可以為文件的英文字句進行建議，將感激不盡！
    - 直接提交 pr 或聯繫我均可
    - `xm35p4fu6[at]gmail[dot]com`
- 假設您已經裝好 [install gtest package](https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/)，則可以直接編輯源碼後 `make test` 編譯。

## 簡介 (求英文版)

`sw::wrapper` 是一個將 container 再次打包的 template class，只要是有支援 `size()`, `operator[size_type]` 皆可。  

注意 `map` 為 `operator[key_type]` 故不支援，如果使用 `sw::wrapper` 來包裝 `map` 將導致不可預知的行為。  

在 `sw::wrapper<container, false>` 時代表不做任何檢查，此時所有檢查式將不會被使用(以及編譯)，因此可以視為原生的 container 類別。

`sw::wrapper_s` 額外提供特殊位置的檢查，可以幫助我們確認某些 index 不會被使用到的，此類別多維護一個 vector 來存所有要被額外檢查的位置。

更多ä½¿用方法可以查看 `unit_test/wrapper_test.cpp`。
