## Demo 

[Demo](http://rainboy.coding.me/rmarkedEditor/)

## install

add package.json

```
  "dependencies": {
    "rmarkedEditor": "git+https://github.com/BlogProject/rmarkedEditor.git",
  },
```

run cmd in bash

```
npm i 
```

## USE

```
//全局使用
import Vue from 'vue'
import rmarkedEditor from 'rmarkedEditor'

//引入样式
import  'codemirror/lib/codemirror.css'
import "rmarkedEditor/src/css/simplemde.css"
import "rmarked/css/github-markdown.css"
import "katex/dist/katex.min.css"
import "highlight.js/styles/tomorrow-night-blue.css"

Vue.use(rmarkedEditor)
```

在组件内


```
<markdown-editor
  v-model="input"
  :configs="configs"
  >
</markdown-editor>
```


```
// 单个组件内使用
```

## Props

| 属性          | 类型    | 默认值 | 描述                                                                         |
| ----          | -----   | -----  | ----                                                                         |
| value         | String  | 无     | 初始值，可使用v-model绑定                                                    |
| preview-class | String  | 无     | 自定义预览样式类                                                             |
| autoinit      | Boolean | true   | 是否自动初始化                                                               |
| highlight     | Boolean | false  | 是否开启高亮                                                                 |
| sanitize      | Boolean | false  | 开启后不渲染输入的html                                                       |
| configs       | Object  | {}     | [SimpleMDE的配置项](https://github.com/sparksuite/simplemde-markdown-editor) |



## example


```
<code-editor
  v-model="code"
  :options="codeOpts">
</code-editor>

```

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
