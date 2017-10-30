## install

package.json

```
  "dependencies": {
    "rmarkedEditor": "git+https://github.com/BlogProject/rmarkedEditor.git",
  },
```

bash

```
npm i 
```

## USE

```
//全局使用
import Vue from 'vue'
import rmarkedEditor from 'rmarkedEditor'

Vue.use(rmarkedEditor)
```

```
// 单个组件内使用
```

## Props


## example


## use as code ide


## 快速键

默认的cmd:`ctrl`

| 快捷键        | 操作           |
| :-------      | :-----         |
| *Cmd-'*       | '引用'         |
| *Cmd-B*       | '加粗'         |
| *Cmd-E*       | '清除格式'     |
| *Cmd-H*       | '缩小标题'     |
| *Cmd-I*       | '斜体'         |
| *Cmd-K*       | '插入链接'     |
| *Cmd-L*       | '插入无序列表' |
| *Cmd-P*       | '预览'         |
| *Cmd-Alt-C*   | '插入代码块'   |
| *Cmd-Alt-I*   | '插入图片'     |
| *Cmd-Alt-L*   | '插入有序列表' |
| *Shift-Cmd-H* | '增大标题'     |
| *F9*          | '全屏预览'     |
| *F11*         | '全屏'         |

## Thanks for

 - [SimpleMDE]()
 - [Vue-SimpleMDE]()
 - [marked]()
 - [editor]()

## Licence

MIT
