# Vue3
Here is a list of resources to learn Vue3.
[vue 3 tutorial](https://www.youtube.com/watch?v=YrxBCBibVo0&list=PL4cUxeGkcC9hYYGbV60Vq3IXYNfDk8At1)
[vue 3 doc](https://cn.vuejs.org/guide/introduction)
[vue 3 code](https://www.bilibili.com/video/BV1K24y1q7eJ/?spm_id_from=333.1007.top_right_bar_window_default_collection.content.click&vd_source=e0c5d304125ac648272a937672080091)

## Introduction
Vue.js 是一套构建用户界面的渐进式框架。Vue 的核心库只关注视图层，不仅易于上手，还便于与第三方库或既有项目整合。Vue 也有配套的工具库，如 Vue Router、Vuex、Vue CLI 等，为开发单页应用提供了强大的支持。

渐进式的意思是 Vue 被设计为自底向上逐层应用。Vue 的核心库只关注视图层，不仅易于上手，还便于与第三方库或既有项目整合。另一方面，Vue 完全有能力驱动采用单文件组件和 Vue 生态系统支持的库开发的复杂单页应用。

Vue 3的优势在于，对于传统页面，链接的点击需要与后端交互，而对于单页面应用，链接的点击只是改变了页面的内容，不需要与后端交互，这样就提高了页面的响应速度。

单页面应用的优势在于，用户体验好，页面切换快，不需要每次都与后端交互，只需要加载一次，后续的页面切换只是改变页面的内容，不需要重新加载页面，这样就提高了页面的响应速度。

Vue 3 相对于 Vue 2 的更新内容：
> - Composition API: Vue 3 中引入了 Composition API，它是一种基于函数的 API，可以让你更灵活地组织组件的逻辑。
> - Teleport: Vue 3 中引入了 Teleport，它可以让你在 DOM 中的任何地方渲染组件。
> - Suspense: Vue 3 中引入了 Suspense，它可以让你在异步组件中添加 loading 状态。
> - Fragment: Vue 3 中引入了 Fragment，它可以让你在组件中返回多个根元素。
> - 支持 TypeScript: Vue 3 对 TypeScript 的支持更加友好。
> - 更好的性能: Vue 3 的性能比 Vue 2 更好，这是因为 Vue 3 中使用了 Proxy 代替了 Object.defineProperty，这样可以更好地监听对象的变化。
> - 更小的体积: Vue 3 的体积比 Vue 2 更小，这是因为 Vue 3 中移除了一些不常用的 API。
>

组合式API和选项式API的区别：
> - 选项式API：Vue 2.x 中的 API，通过选项式 API，我们可以在一个对象中定义组件的属性、方法、生命周期钩子等，使用这些来定义组件。选项所定义的属性会暴露在组件的实例上，可以通过 this 访问。
> - 组合式API：Vue 3.x 中的 API，通过组合式 API，我们可以使用函数来定义组件的属性、方法、生命周期钩子等，使用这些来定义组件。组合式 API 可以让我们更好地组织组件的逻辑，可以更好地复用逻辑。

## Vue 3 Tutorial to get started
在这一部分将会跟随 Vue 3 tutorial 进行初步知识的学习。

我们的学习目标是制作出一个小组件到html页面上。

