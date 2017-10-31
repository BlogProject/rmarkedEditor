<template>
  <div class="markdown-editor">
    <textarea></textarea>
  </div>
</template>

<script>
var SimpleMDE = require("./simplemde.js")
export default {
  name:"markdown-editor",
  data(){
    return {
    }
  },
  props:{
    value:String,
    previewClass:String,
    configs:{
      type:Object,
      default(){
        return {}
      }
    }
  },
  mounted(){
    this.initialize();
  },
  methods:{

    initialize() {
      const configs = {
        element: this.$el.firstElementChild,
        initialValue: this.value,
        renderingConfig: {},
      };
      Object.assign(configs, this.configs);
      // 判断是否开启代码高亮
      if (this.highlight) {
        configs.renderingConfig.codeSyntaxHighlighting = true;
      }
      // 设置是否渲染输入的html
      //marked.setOptions({ sanitize: this.sanitize });
      // 实例化编辑器
      this.simplemde = new SimpleMDE(configs);
      // 添加自定义 previewClass
      const className = this.previewClass || '';
      // 绑定事件
      this.bindingEvents();
    },
    bindingEvents() {
      this.simplemde.codemirror.on('change', () => {
        this.$emit('input', this.simplemde.value());
      });
    },
  },
  destroyed() {
    this.simplemde = null;
  },
  watch: {
    value(val) {
      if (val === this.simplemde.value()) return;
      this.simplemde.value(val);
    },
  },

}

</script>

<style>
.markdown-editor {
  font-size:16px;
}
</style>
